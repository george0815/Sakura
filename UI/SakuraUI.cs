using Terminal.Gui.App;
using Terminal.Gui.ViewBase;
using Terminal.Gui.Views;



namespace sakura;


public class SakuraUI
{

    public static void Run()
    {

        using IApplication app = Application.Create().Init();


        app.Run<SakuraWindow>();


    }


}


public class SakuraWindow : Window
{

    public SakuraWindow()
    {
        Title = "Sakura";

        Width = Dim.Fill();
        Height = Dim.Fill();


        Add(new Label
        {

            Text = "fgkerfjewr",
            X = 1,
            Y = 1


        });
    }

}
