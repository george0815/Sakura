using Terminal.Gui.Drawing;
using System.Text.Json;
using sakura.helpers;

namespace sakura
{

    /// <summary>
    /// Holds all configurable settings and UI variables for the application.
    /// </summary>
    internal class SettingsData
    {
        // ------------------------------
        // UI Variables
        // ------------------------------
        public static ushort HeaderHeight { get; set; } = 15;  // Default header height
        public static ushort LogoWidth { get; set; } = 55;     // Width of ASCII logo display

        // ------------------------------
        // Network Ports
        // ------------------------------
        public ushort Port { get; set; } = 55123;             // Main listening port
        public ushort DhtPort { get; set; } = 55124;          // DHT listening port

        // ------------------------------
        // Maximum connections / transfer rates
        // ------------------------------
        public ushort MaxConnections { get; set; } = 100;
        public int MaxDownloadSpeed { get; set; } = 100 /* to KB*/ * 1024 /* to MB*/ * 1024;
        public int MaxUploadSpeed { get; set; } = 100 /* to KB*/ * 1024 /* to MB*/ * 1024;
        public int RefreshInterval { get; set; } = 1000;      // UI refresh interval (ms)

        // ------------------------------
        // Client behavior flags
        // ------------------------------
        public bool DetailedLogging { get; set; } = true;
        public bool StopSeedingWhenFinished { get; set; } = true;
        public bool EnablePortForwarding { get; set; } = true;
        public bool HidetextCursor { get; set; } = true;
        public bool DisableColoredHotkeyInfo { get; set; } = false;
        public bool DisableASCII { get; set; } = false;

        // ------------------------------
        // Paths
        // ------------------------------
        public string? DefaultDownloadPath { get; set; } = "./";  // Default download folder
        public string? LogPath { get; set; } = "./log.txt";       // Log file path
        public string SettingsPath { get; set; } = "cfg.json";    // Settings file

        // ------------------------------
        // UI Colors
        // ------------------------------
        public Color BackgroundColor { get; set; } = Color.Black;
        public Color TextColor { get; set; } = Color.White;
        public Color FocusBackgroundColor { get; set; } = Color.White;
        public Color FocusTextColor { get; set; } = Color.Black;
        public Color HotTextColor { get; set; } = Color.BrightYellow;
        public Color LogoColor { get; set; } = Color.BrightCyan;


        // ------------------------------
        // UseSystemConsole 
        // ------------------------------

        public bool UseSystemConsole { get; set; } = false;


        //
        // ------------------------------
        // ASCII / Icons
        // ------------------------------
        public List<string> Icons { get; set; } = ASCII.icons;

    }


    /// <summary>
    /// Provides global access to the current settings instance, 
    /// and handles saving/loading from JSON.
    /// </summary>
    internal static class Settings
    {
        /// <summary>
        /// The currently loaded settings.
        /// </summary>
        internal static SettingsData Current { get; private set; } = new();

        /// <summary>
        /// Options for JSON serialization.
        /// </summary>
        private static readonly JsonSerializerOptions JsonOptions = new() { WriteIndented = true };

        /// <summary>
        /// Converts current settings into MonoTorrent EngineSettingsBuilder.
        /// </summary>

        #region SAVE/LOAD

        /// <summary>
        /// Saves current settings to disk in JSON format.
        /// </summary>
        internal static void Save()
        {
            try
            {
                var json = JsonSerializer.Serialize(Current, JsonOptions);
                File.WriteAllText(Current.SettingsPath ?? "cfg.json", json);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{"Error saving settings"} {ex.Message}");
            }
        }

        /// <summary>
        /// Loads settings from disk or creates default if missing or corrupted.
        /// </summary>
        internal static void Load()
        {
            try
            {
                if (!File.Exists(Current.SettingsPath))
                {
                    Settings.Save();
                    return;
                }

                string json = File.ReadAllText(Current.SettingsPath);
                var loaded = JsonSerializer.Deserialize<SettingsData>(json, JsonOptions);

                if (loaded != null)
                {
                    Current = loaded;

                    // Reduce header height if ASCII art disabled
                    if (Current.DisableASCII)
                        SettingsData.HeaderHeight = 5;
                }
                else
                {
                    Settings.Save();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{"Error loading settigns"} {ex.Message}");
                Settings.Save();
            }
        }

        #endregion
    }
}
