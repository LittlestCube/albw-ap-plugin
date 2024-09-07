#ifndef CHEATS_H
#define CHEATS_H

#include <CTRPluginFramework.hpp>
#include "Helpers.hpp"
#include "Unicode.h"

namespace CTRPluginFramework {
    using StringVector = std::vector<std::string>;
	
    struct States
	{
        const char  *stateName;
        const u8    stateID;
    };
	
	struct Countries
	{
        const char  *countryName;
        const u8    countryID;

        const std::vector<States> countryStates;
    };
	
	struct Coordinates
	{
		const char  *globeLocation;
		const u32    id;
	};

    extern const std::vector<Countries> g_flags;
	extern const std::vector<Coordinates> g_coords;

	void	alwaysBlinking(MenuEntry *entry);
    void    alwaysStarPower(MenuEntry *entry);
	void   	CycleSetter(MenuEntry *entry);
	void   	starPowerCycler(MenuEntry *entry);
	void   	disableStarAcceleration(MenuEntry *entry);
    void	alwaysSmall(MenuEntry *entry);
    void	instantSmallRecovery(MenuEntry *entry);
    void	alwaysBlackKart(MenuEntry *entry);
    void	instantBlooperRecovery(MenuEntry *entry);
	void	alwaysFlat(MenuEntry *entry);
    void	instantFlatRecovery(MenuEntry *entry);
    void	neverFlatRecovery(MenuEntry *entry);
    void	alwaysGlider(MenuEntry *entry);
    void	alwaysConfused(MenuEntry *entry);
	void	microKart(MenuEntry *entry);
    void	controlKiller(MenuEntry *entry);
    void	disableWalls(MenuEntry *entry);
    void	driveBounds(MenuEntry *entry);
	void	rapidfire(MenuEntry *entry);
	void	itemsKiller(MenuEntry *entry);
	void	lookBack(MenuEntry *entry);
	void	itemDespawner(MenuEntry *entry);
	void	instantRespawn(MenuEntry *entry);
	void	turningSpeed(MenuEntry *entry);
	void	disableLuckyShroom(MenuEntry *entry);
	void	disableFirstPersonView(MenuEntry *entry);
    void	trickAnywhere(MenuEntry *entry);
    void	driveWalls(MenuEntry *entry);
    void	autopilot(MenuEntry *entry);
    void	autoJump(MenuEntry *entry);
    void	stopTanooki(MenuEntry *entry);
    void	instantMT(MenuEntry *entry);
    void	insideDrift(MenuEntry *entry);
    void	hugeBunnyhop(MenuEntry *entry);
    void    sizeChanger(MenuEntry *entry);
    void	instantAcceleration(MenuEntry *entry);
	void	instantBackAcceleration(MenuEntry *entry);
    void	instantStop(MenuEntry *entry);
	void	AutomSetter(MenuEntry *entry);
	void	autoForward(MenuEntry *entry);
    void	fastReverse(MenuEntry *entry);
    void    SpeedSetter(MenuEntry *entry);
    void	forceSpeed(MenuEntry *entry);
    void    BackSetter(MenuEntry *entry);
    void	forceBack(MenuEntry *entry);
    void	moonjump(MenuEntry *entry);
    void    freefly(MenuEntry *entry);
    void	stalking(MenuEntry *entry);
    void	driveAnywhere(MenuEntry *entry);
    void	aimbot(MenuEntry *entry);
    void	blueShellRide(MenuEntry *entry);
    void	GravitySetter(MenuEntry *entry);
    void	gravityForce(MenuEntry *entry);
	void	touchCode(MenuEntry *entry);
    void	saveSlotTeleporter(MenuEntry *entry);
	void	itemWheelDeluxe(MenuEntry *entry);
    void	masterItemHack(MenuEntry *entry);
	void    ItemSetter(MenuEntry *entry);
    void	forceItem(MenuEntry *entry);
    void    ItemBoxSetter(MenuEntry *entry);
    void	forceBox(MenuEntry *entry);
	void	randomShell(MenuEntry *entry);
    void    randomItems(MenuEntry *entry);
    void    trulyRandomItems(MenuEntry *entry);
	void	popItems(MenuEntry *entry);
	void	dropItems(MenuEntry *entry);
    void	dropLuckyShroom(MenuEntry *entry);
    void	dropLuckyStar(MenuEntry *entry);
    void	dropLuckyBlooper(MenuEntry *entry);
    void	dropMushroom(MenuEntry *entry);
    void	starLimit(MenuEntry *entry);
	void	shroomLimit(MenuEntry *entry);
	void	bombLimit(MenuEntry *entry);
	void	bananaLimit(MenuEntry *entry);
	void	fireballLimit(MenuEntry *entry);
	void	blooperLimit(MenuEntry *entry);
    void	killerSpeed(MenuEntry *entry);
    void	fastBlueShell(MenuEntry *entry);
    void	stoppedBlueShell(MenuEntry *entry);
    void	blueShellInstantHit(MenuEntry *entry);
    void	fastGreenShell(MenuEntry *entry);
    void	stoppedGreenShell(MenuEntry *entry);
    void	SizeSetter(MenuEntry *entry);
    void	bananaSize(MenuEntry *entry);
    void	fireballSize(MenuEntry *entry);
    void	bombSize(MenuEntry *entry);
	void	rotatingBananas(MenuEntry *entry);
    void	invisibleLightning(MenuEntry *entry);
    void    LightningColorSetter(MenuEntry *entry);
    void	lightningColor(MenuEntry *entry);
    void	lightningSelfstriking(MenuEntry *entry);
    void	blooperSelfstriking(MenuEntry *entry);
    void	noItemClear(MenuEntry *entry);
    void	stuckedLucky(MenuEntry *entry);
    void	stuckedLuckyItem(MenuEntry *entry);
    void	noBombJump(MenuEntry *entry);
    void	jumpingBomb(MenuEntry *entry);
    void	noRotation(MenuEntry *entry);
    void	flyingStar(MenuEntry *entry);
    void	inflatableStar(MenuEntry *entry);
	void	NoDC(MenuEntry *entry);
	void    TimeIndicator(MenuEntry *entry);
	void	removeLakitu(MenuEntry *entry);
	void	driveDuringCountdown(MenuEntry *entry);
	void	noCountdown(MenuEntry *entry);
    void	instantCountdown(MenuEntry *entry);
    void	cpuBrawl(MenuEntry *entry);
    void	cpuPropeller(MenuEntry *entry);
	void	waterEverywhere(MenuEntry *entry);
	void	SetPoints(MenuEntry *entry);
    void	randomPoints(MenuEntry *entry);
	void	instantWin(MenuEntry *entry);
    void	battleCoin(MenuEntry *entry);
	void	battleBalloon(MenuEntry *entry);
	void	randCoins(MenuEntry *entry);
	void	randBalloons(MenuEntry *entry);
    void	coinLimit(MenuEntry *entry);
    void    maxTimer(MenuEntry *entry);
    void	minTimer(MenuEntry *entry);
    void	blinkingEffect(MenuEntry *entry);
    void	BlinkSetter(MenuEntry *entry);
	void	antiKouraB(MenuEntry *entry);
	void	balloonsCycler(MenuEntry *entry);
	void	BalSetter(MenuEntry *entry);
	void	forceBal(MenuEntry *entry);
	void    SetCountry(MenuEntry *entry);
    void	SetCoord(MenuEntry *entry);
	void	randomCountry(MenuEntry *entry);
    void	randomCoordinates(MenuEntry *entry);
    void    SetFlag(MenuEntry *entry);
    void    SetState(MenuEntry *entry);
	void    SetCoordinates(MenuEntry *entry);
	void	vrExtender(MenuEntry *entry);
	void	SetVR(MenuEntry *entry);
	void	vrRandomizer(MenuEntry *entry);
	void    vrIndicator(MenuEntry *entry);
    void    MarkSetter(MenuEntry *entry);
    void	markSelector(MenuEntry *entry);
	void	unlockEverything(MenuEntry *entry);
    void    starAmount(MenuEntry *entry);
    void    starReset(MenuEntry *entry);
    void    SetVrCounter(MenuEntry *entry);
    void	randomVrCounter(MenuEntry *entry);
    void    SetVictories(MenuEntry *entry);
    void	randomVictories(MenuEntry *entry);
    void    SetDefeats(MenuEntry *entry);
    void	randomDefeats(MenuEntry *entry);
    void    SetCoins(MenuEntry *entry);
    void	randomCoins(MenuEntry *entry);
    void    SetStreetpass(MenuEntry *entry);
    void	randomStreetpass(MenuEntry *entry);
    void    SetDriver(MenuEntry *entry);
    void	randomDriverClass(MenuEntry *entry);
	void	KeySetter(MenuEntry *entry);
	void	privateMatchmake(MenuEntry *entry);
	void    MessageSetter(MenuEntry *entry);
    void	messageConfig(MenuEntry *entry);
    void	randomMessage(MenuEntry *entry);
    void	itemSpam(MenuEntry *entry);
	void	highDataRate(MenuEntry *entry);
    void	lagElim(MenuEntry *entry);
    void	lagKart(MenuEntry *entry);
    void	pauseOnline(MenuEntry *entry);
	void	homeAnywhere(MenuEntry *entry);
	void	skipPass(MenuEntry *entry);
	void	bypassEULA(MenuEntry *entry);
	void	skipLive(MenuEntry *entry);
	void	skipWait(MenuEntry *entry);
	void	antiMatchCrash(MenuEntry *entry);
	void	antiVR(MenuEntry *entry);
	void    MusicSetter(MenuEntry *entry);
    void	trackMusicChanger(MenuEntry *entry);
	void	timeTrialGhost(MenuEntry *entry);
	void    miiDumper(MenuEntry *entry);
	void    speedometer(MenuEntry *entry);
	void	ViewSetter(MenuEntry *entry);
	void	forceView(MenuEntry *entry);
    void	disableStarMusic(MenuEntry *entry);
    void	fastGame(MenuEntry *entry);
	void	explosiveMode(MenuEntry *entry);
	void	mariokartdsMode(MenuEntry *entry);
	void    DifficultySetter(MenuEntry *entry);
	void	survivorMode(MenuEntry *entry);
    void	CountdownMode(MenuEntry *entry);
    void	TwoHundredCCStable(MenuEntry *entry);
    void	FiveHundredCCStable(MenuEntry *entry);
    void    contactMe(MenuEntry *entry);
    void    pluginInfo(MenuEntry *entry);
	
}
#endif