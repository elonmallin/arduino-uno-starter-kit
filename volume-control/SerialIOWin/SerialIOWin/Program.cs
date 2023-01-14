using AudioSwitcher.AudioApi.CoreAudio;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SerialIOWin
{
    internal class Program
    {
        public static float Remap(float value, float from1, float to1, float from2, float to2)
        {
            return (value - from1) / (to1 - from1) * (to2 - from2) + from2;
        }

        static void Main(string[] args)
        {
            var audio = new CoreAudioController().DefaultPlaybackDevice;
            Console.WriteLine(audio.Volume);

            var serialPort = new SerialPort();
            serialPort.PortName = "COM3";
            serialPort.BaudRate = 9600;
            serialPort.Open();

            int oldVolume = 0;
            int volume = 0;
            while (true)
            {
                Thread.Sleep(100);
                while (serialPort.BytesToRead > 0)
                {
                    volume = serialPort.ReadByte();
                }
                Console.WriteLine(volume);

                if (volume != oldVolume)
                {
                    audio.Volume = Remap(volume, 0, 100, 0, 50);
                }

                oldVolume = volume;
            }
        }
    }
}
