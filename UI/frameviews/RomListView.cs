
using System.Data;
using Terminal.Gui;
using sakura.helpers;

namespace sakura.frameviews
{

    /// <summary>
    /// Displays a list of active torrents with progress, peers, rates, and controls
    /// for starting, stopping, seeding, and removing torrents.
    /// 
    /// This view is backed by a TableView and synchronizes with TorrentOperations events.
    /// </summary>
    public class RomListView : FrameView
    {
        /// <summary>
        /// List of roms backing this view.
        /// </summary>
        private readonly List<Rom> _roms;

        /// <summary>
        /// Terminal.Gui table showing rom info.
        /// </summary>
        private readonly TableView _table;

        /// <summary>
        /// DataTable holding the rom rows displayed in _table.
        /// </summary>
        private readonly DataTable _tableData;

        /// <summary>
        /// Initialize the rom list view with the provided roms.
        /// </summary>
        /// <param name="roms">List of rom objects</param>
        public RomListView(List<Rom> roms)
            : base(Resources.Roms)
        {
            _roms = roms;

            X = 20;
            Y = SettingsData.HeaderHeight;
            Width = Dim.Fill();
            Height = Dim.Fill();

            // --- Table Schema ---
            _tableData = new DataTable();

            // Define visible columns in a consistent order
            _tableData.Columns.Add(Resources.Name, typeof(string));
            _tableData.Columns.Add("Path", typeof(string));
            _tableData.Columns.Add("SRAM data path", typeof(string));
            _tableData.Columns.Add("Display mode", typeof(string));

            // --- TableView Setup ---
            _table = new TableView()
            {
                X = 0,
                Y = 0,
                Width = Dim.Fill(),
                Height = Dim.Fill(),
                Table = _tableData
            };

            Add(_table);

            foreach (Rom rom in _roms)
            {
                _tableData.Rows.Add(rom.Name, rom.RomPath, rom.SramPath, rom.NTSC ? "NTSC" : "PAL");
            }

            _table.Update();
            _table.SetNeedsDisplay();

        }

        /// <summary>
        /// Handles keyboard input for torrent control.
        /// Supports start/stop download, start/stop seeding, remove, and magnet link generation.
        /// </summary>
        /// <param name="keyEvent">The key event pressed by the user</param>
        /// <returns>True if the key was handled, otherwise false</returns>
        public override bool ProcessKey(KeyEvent keyEvent)
        {
            // Safety: ignore if no row is selected
            if (_table.SelectedRow < 0 || _table.SelectedRow >= _roms.Count)
                return base.ProcessKey(keyEvent);

            // --- Start download ---
            if (keyEvent.Key == Settings.Current.Controls.StartRom)
            {
                // Task.Run(async () =>

                SearchArgs args = new SearchArgs()
                {
                    RomPath = _roms[_table.SelectedRow].RomPath,
                };
                Log.Write($"STARTING {_roms[_table.SelectedRow].RomPath}");
                CoreWrapper.Launch(args);


                Log.Write(_table.SelectedRow.ToString());
                Log.Write("STARTING ROM");
                return true;
            }

            // --- Stop download ---
            else if (keyEvent.Key == Settings.Current.Controls.StopRom)
            {
                Task.Run(async () =>
                {
                });

                Log.Write(_table.SelectedRow.ToString());
                return true;
            }




            return base.ProcessKey(keyEvent);
        }

    }
}
