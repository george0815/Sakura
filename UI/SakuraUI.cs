using Terminal.Gui.App;
using System.Collections.ObjectModel;
using Terminal.Gui.Drawing;
using Terminal.Gui.ViewBase;
using Terminal.Gui.Views;



namespace sakura;


public class SakuraUI
{

    public static void Run()
    {

        using IApplication app = Application.Create().Init();

        Scheme LogoScheme = new()
        {
            Normal = new Terminal.Gui.Drawing.Attribute(Settings.Current.LogoColor, Settings.Current.BackgroundColor),
            Focus = new Terminal.Gui.Drawing.Attribute(Settings.Current.LogoColor, Settings.Current.BackgroundColor),
        };



        app.Run<SakuraWindow>();


    }


}


public class SakuraWindow : Window
{

    // Header components
    readonly private FrameView header;

    public SakuraWindow()
    {
        Title = "Sakura";

        Width = Dim.Fill();
        Height = Dim.Fill();


        #region HEADER

        //Header container  
        header = new FrameView()
        {
            X = 0,
            Y = 0,
            Width = Dim.Fill(),
            Height = 15,
            BorderStyle = LineStyle.None
        };



        // Scrollable area inside header
        var headerScroll = new View()
        {
            X = 0,
            Y = 0,
            Width = Dim.Fill(),
            Height = Dim.Fill(),
            BorderStyle = LineStyle.None
        };

        header.Add(headerScroll);


        // ASCII logo frame
        var logoFrame = new FrameView()
        {
            X = 0,
            Y = 0,
            Width = Settings.Current.DisableASCII ? 0 : SettingsData.LogoWidth,
            Height = SettingsData.HeaderHeight,
            BorderStyle = LineStyle.Single
        };

        var logo = new Label()
        {
            X = 0,
            Y = 0,
            Width = Dim.Fill(),
            Height = Dim.Fill(),
            Text = Settings.Current.Icons[0],
            SchemeName = "Logo"
        };

        // Add logo only if ASCII art is enabled
        if (!Settings.Current.DisableASCII)
        {
            logoFrame.Add(logo);
            header.Add(logoFrame);
        }

        Add(header);

        #endregion

        #region SIDEBAR AND MENU 


        // Sidebar container
        var sidebar = new FrameView()
        {
            X = 0,
            Y = SettingsData.HeaderHeight,
            Width = 20,
            Height = Dim.Fill(),
            BorderStyle = LineStyle.Rounded
        };

        // Sidebar menu
        var items = new ObservableCollection<string> { "Roms" };
        var menu = new ListView()
        {

            X = 1,
            Y = 0,
            Width = Dim.Fill(),
            Height = Dim.Fill() - 3,
            Source = new ListWrapper<string>(items)

        };


        // Switch content panel when menu selection changes
        menu.SelectedItemChanged += (args) =>
        {
            SwitchPanel(args.Item, ref logo);
        };

        sidebar.Add(menu);

        // Exit button
        var exitButton = new Button()
        {
            Text = "Exit",
            X = 1,
            Y = Pos.Bottom(menu),
            Width = 16
        };

        exitButton.Accepting += (_, _) => { ShowExitDialog(); };

        sidebar.Add(exitButton);

        // Add sidebar to window
        Add(sidebar);

        #endregion



        Add(new Label
        {

            Text = "fgkerfjewr",
            X = 1,
            Y = 1


        });
    }

}
