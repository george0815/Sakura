using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Text.Json;
using Terminal.Gui;
using System.Text.Json.Serialization;
using System.Linq;
using System.Threading.Tasks;

namespace sakura.helpers
{
    /// <summary>
    /// Represents the JSON response returned by Ghidorah for status queries.
    /// </summary>
    public class StatusResponse
    {
        [JsonPropertyName("paths")]
        public string? Paths { get; set; }  // Paths used in Ghidorah execution

        [JsonPropertyName("message")]
        public string? Message { get; set; } // Optional message from Ghidorah

    }


    /// <summary>
    /// Struct to hold arguments for a Ghidorah search.
    /// </summary>
    internal struct SearchArgs
    {
        internal string RomPath;       // Search query
    }

    /// <summary>
    /// Handles interaction with the Ghidorah executable for searches and plugin checks.
    /// </summary>
    internal class CoreWrapper
    {
        // Determine executable name based on OS
        internal static readonly string ExeFileName = OperatingSystem.IsWindows() ? "sakura_core.exe" : "/home/Hunter/Documents/Github/sakura/build/sakura";


        // JsonSerializerOptions instance
        private static readonly JsonSerializerOptions CachedJsonOptions = new() { PropertyNameCaseInsensitive = true };



        /// <summary>
        /// Executes a search using Ghidorah with the given arguments.
        /// </summary>
        internal static string Launch(SearchArgs args)
        {
            // Convert arrays to space-separated strings for CLI

            var psi = new ProcessStartInfo
            {
                FileName = ExeFileName,
                Arguments =
                    $"--rom {args.RomPath}",
                //$"--limit {NormArgs.Limit} ",
                /* $"--total_limit {NormArgs.TotalLimit} " +
                 $"--categories {categories} " +
                 $"--sort_by {NormArgs.SortBy} " +
                 $"--sources {sources}", */
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = false,
                StandardOutputEncoding = Encoding.UTF8,
                StandardErrorEncoding = Encoding.UTF8
            };

            Log.Write("STARTING");

            using var process = new Process { StartInfo = psi };
            process.Start();

            // Asynchronously read stdout and stderr
            var outputTask = process.StandardOutput.ReadToEndAsync();
            var errorTask = process.StandardError.ReadToEndAsync();


            Task.WaitAll(outputTask, errorTask);

            string output = outputTask.Result;
            string error = errorTask.Result;

            if (process.ExitCode != 0)
            {
                Log.Write($"{Resources.Ghidoraherror} {error}");
                return $"{{\"data\":[],\"errors\":[\"{Resources.Errorwrittentolog}\"]}}";
            }

            return output; // Return JSON search result
        }






    }
}



