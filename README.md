# ALBW AP on a 3DS

## CURRENTLY THIS MUST BE GENERATED/RUN ON THE CUSTOM VERSION OF THE APWORLD!! You need to install the included `.pyd`/`.so` file too.

1. Download the `plugin.3gx`, `albw-ap-plugin-support.apworld`, `.pyd` file (or `.so` file on non-windows) and `Luma3DS` files from [releases](https://github.com/LittlestCube/albw-ap-plugin/releases/latest).

2. On your 3DS's SD card, rename your original `boot.firm` file to something like `boot.firm.bak`.

3. Copy the `boot.firm` from the `Luma3DS` zip you downloaded to the root of your SD card.

4. Copy `plugin.3gx` to `/luma/plugins/00040000000EC300/` on your SD card.

5. Install the apworld file, and copy the `.pyd`/`.so` file to `Archipelago/lib`.

6. Once you generate a patch from the APWorld, copy it to `/luma/titles/00040000000EC300/` on your SD card.

7. Re-insert your SD card into your 3DS and power it on.
	- If you used FTP to transfer your files, and copied the new Luma `boot.firm` file, reboot your 3DS now.

8. On the Luma3DS configuration screen after power-up:
	1. _Make sure_ that `Enable loading external FIRMs and modules` does **NOT** have an x next to it. If so, disable it.
	2. Turn `Enable game patching` on and make sure it **DOES** have an x next to it.
	3. Press Start or choose `Save and exit`.

9. Press L+DPadDown+Select to open the Rosalina menu, and make sure that `Plugin loader` is set to `[Enabled]`.

10. Run A Link Between Worlds.

11. At the end of the red 3DS loading screen, you should see a blue flash. This means the plugin has loaded successfully.

12. Run the command on-screen into your ALBW APWorld client.

13. Profit.