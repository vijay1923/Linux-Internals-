USING USBIPD TO ACCESS USB SERIAL DEVICE IN WSL (UBUNTU)

Since this program runs inside WSL, the USB device must be
attached from Windows using PowerShell. WSL does not have
direct access to USB devices by default.

Steps:

1) Open PowerShell as Administrator.

2) List available USB devices:
       usbipd list

   Look for your device (for example: USB Serial CH340) and
   note the BUSID (example: 1-9). The BUSID may change if you
   plug the device into a different USB port.

3) Share the device with WSL (only required once):
       usbipd bind --busid <BUSID> --force

4) Attach the device to WSL:
       usbipd attach --busid <BUSID> --wsl

After attaching, the device will appear in Ubuntu as a Linux
serial device, usually:

       /dev/ttyUSB0

You can confirm this inside Ubuntu by running:
       ls /dev/ttyUSB*

Then run the program normally:
       ./serialmon

------------------------------------------------------------

DETACHING THE DEVICE (Return control to Windows):

       usbipd detach --busid <BUSID>

Detach all devices:
       usbipd detach -a

Other useful options:
       -a, --all                    Detach all devices
       -b, --busid <BUSID>          Detach device with BUSID
       -i, --hardware-id <VID:PID>  Detach devices with VID:PID
       -h, --help                   Show help information

------------------------------------------------------------

NOTE:

If the USB device is unplugged and plugged again, it must be
attached to WSL again using:

       usbipd attach --busid <BUSID> --wsl