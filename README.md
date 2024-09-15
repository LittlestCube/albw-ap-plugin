# ALBW AP on a 3DS

## CURRENTLY THIS MUST BE GENERATED/RUN ON THE CUSTOM VERSION OF THE APWORLD!! You need to install the included `.pyd`/`.so` file too.

1. Download the `plugin.3gx` and `Luma3DS` files from [releases](https://github.com/LittlestCube/albw-ap-plugin/releases/latest).

2. On your 3DS's SD card, rename your original `boot.firm` file to something like `boot.firm.bak`.

3. Copy the `boot.firm` from the `Luma3DS` zip you downloaded to the root of your SD card.

4. Copy `plugin.3gx` to `/luma/plugins/00040000000EC300/` on your SD card.

5. Once you generate a patch from the APWorld, copy it to `/luma/titles/00040000000EC300/` on your SD card.

6. Re-insert your SD card into your 3DS and power it on.

7. On the Luma3DS configuration screen after power-up:

	1. _Make sure_ that `Enable loading external FIRMs and modules` does **NOT** have an x next to it. If so, disable it.
	2. Turn `Enable game patching` on and make sure it **DOES** have an x next to it.
	3. Press Start or choose `Save and exit`.

8. Run A Link Between Worlds.

9. At the end of the red 3DS loading screen, you should see a blue flash. This means the plugin has loaded successfully.

10. Run the command on-screen into your ALBW APWorld client.

11. Profit.