#pragma once
#include "Setting.h"
#include "ISettingsSerialiser.h"
#include "GUIServiceInfo.h"

class SettingsStateAndEvents
{
private:
	std::shared_ptr<ISettingsSerialiser> mSerialiser;

public:
	SettingsStateAndEvents(std::shared_ptr<ISettingsSerialiser> serialiser)
		: mSerialiser(serialiser)
	{ 
		mSerialiser->deserialise(allSerialisableOptions); 
	
	}
	~SettingsStateAndEvents() {
		PLOG_DEBUG << "~SettingsStateAndEvents()";
		mSerialiser->serialise(allSerialisableOptions); 
	};

	//	hotkeys
	std::shared_ptr<ActionEvent> toggleGUIHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> togglePauseHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> speedhackHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> invulnerabilityHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> aiFreezeHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> medusaHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> naturalCheckpointDisableHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> infiniteAmmoHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> bottomlessClipHotkeyEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> display2DInfoHotkeyEvent = std::make_shared<ActionEvent>();


	// events
	std::shared_ptr<ActionEvent> showGUIFailures = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> advanceTicksEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceCheckpointEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceRevertEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceDoubleRevertEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceCoreSaveEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceCoreLoadEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> injectCheckpointEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> dumpCheckpointEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> injectCoreEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> dumpCoreEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> consoleCommandEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> getObjectAddressEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceTeleportEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceTeleportFillWithCurrentPositionEvent = std::make_shared<ActionEvent>();
	std::shared_ptr<ActionEvent> forceLaunchEvent = std::make_shared<ActionEvent>();


	// settings
	std::shared_ptr<Setting<bool>> GUIWindowOpen = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(GUIWindowOpen)
		);

	std::shared_ptr<Setting<bool>> GUIShowingFreesCursor = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(GUIShowingFreesCursor)
		);


	std::shared_ptr<Setting<bool>> GUIShowingBlocksInput = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(GUIShowingBlocksInput)
		);

	std::shared_ptr<Setting<bool>> GUIShowingPausesGame = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(GUIShowingPausesGame)
		);

	std::shared_ptr<Setting<bool>> togglePause = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(togglePause)
		);

	std::shared_ptr<Setting<bool>> pauseAlsoBlocksInput = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(pauseAlsoBlocksInput)
		);

	std::shared_ptr<Setting<bool>> pauseAlsoFreesCursor = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(pauseAlsoFreesCursor)
		);

	std::shared_ptr<Setting<int>> advanceTicksCount = std::make_shared<Setting<int>>
		(
			1,
			[](int in) { return in > 0; }, // must be positive
			nameof(advanceTicksCount)
		);

	std::shared_ptr<Setting<bool>> injectionIgnoresChecksum = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectionIgnoresChecksum)
		);

	std::shared_ptr<Setting<bool>> injectCheckpointForcesRevert = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCheckpointForcesRevert)
		);

	std::shared_ptr<Setting<bool>> injectCheckpointLevelCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCheckpointLevelCheck)
		);

	std::shared_ptr<Setting<bool>> injectCheckpointVersionCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCheckpointVersionCheck)
		);

	std::shared_ptr<Setting<bool>> injectCheckpointDifficultyCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCheckpointDifficultyCheck)
		);

	std::shared_ptr<Setting<bool>> autonameCheckpoints = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(autonameCheckpoints)
		);

	std::shared_ptr<Setting<bool>> dumpCheckpointForcesSave = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(dumpCheckpointForcesSave)
		);

	std::shared_ptr<Setting<bool>> injectCoreForcesRevert = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCoreForcesRevert)
		);

	std::shared_ptr<Setting<bool>> injectCoreLevelCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCoreLevelCheck)
		);

	std::shared_ptr<Setting<bool>> injectCoreVersionCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCoreVersionCheck)
		);

	std::shared_ptr<Setting<bool>> injectCoreDifficultyCheck = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(injectCoreDifficultyCheck)
		);

	std::shared_ptr<Setting<bool>> dumpCoreForcesSave = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(dumpCoreForcesSave)
		);

	std::shared_ptr<Setting<bool>> autonameCoresaves = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(autonameCoresaves)
		);

	std::shared_ptr<Setting<bool>> speedhackToggle = std::make_shared<Setting<bool>>
	(
		false,
		[](bool in) { return true; },
		nameof(speedhackToggle)
	);

	std::shared_ptr<Setting<double>> speedhackSetting = std::make_shared<Setting<double>>
	(
		10.f,
		[](float in) { return in > 0; }, // must be positive
		nameof(speedhackSetting)
	);


	std::shared_ptr<Setting<bool>> invulnerabilityToggle = std::make_shared<Setting<bool>>
	(
		false,
		[](bool in) { return true; },
		nameof(invulnerabilityToggle)
	);

	std::shared_ptr<Setting<bool>> invulnerabilityNPCToggle = std::make_shared<Setting<bool>>
	(
		false,
		[](bool in) { return true; },
		nameof(invulnerabilityNPCToggle)
	);

	std::shared_ptr<Setting<bool>> aiFreezeToggle = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(aiFreezeToggle)
		);

	std::shared_ptr<Setting<bool>> medusaToggle = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(medusaToggle)
		);

	std::shared_ptr<Setting<std::string>> consoleCommandString = std::make_shared<Setting<std::string>>
		(
			"game_revert",
			[](std::string in) { return true; },
			nameof(consoleCommandString)
		);


	std::shared_ptr<Setting<uint32_t>> getObjectAddressDWORD = std::make_shared<Setting<uint32_t>>
		(
			0xDEADBEEF,
			[](uint32_t in) { return true; },
			nameof(getObjectAddressDWORD)
		);

	std::shared_ptr<Setting<bool>> forceTeleportApplyToPlayer = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(forceTeleportApplyToPlayer)
		);

	std::shared_ptr<Setting<uint32_t>> forceTeleportCustomObject = std::make_shared<Setting<uint32_t>>
		(
			0xDEADBEEF,
			[](uint32_t in) { return true; },
			nameof(forceTeleportCustomObject)
		);


	std::shared_ptr<Setting<SimpleMath::Vector3>> forceTeleportAbsoluteVec3 = std::make_shared<Setting<SimpleMath::Vector3>>
		(
			SimpleMath::Vector3{ 0.f, 0.f, 0.f },
			[](SimpleMath::Vector3 in) { return true; },
			nameof(forceTeleportAbsoluteVec3)
		);

	std::shared_ptr<Setting<SimpleMath::Vector3>> forceTeleportRelativeVec3 = std::make_shared<Setting<SimpleMath::Vector3>>
		(
			SimpleMath::Vector3{ 5.f, 0.f, 0.f },
			[](SimpleMath::Vector3 in) { return true; },
			nameof(forceTeleportRelativeVec3)
		);

	std::shared_ptr<Setting<bool>> forceTeleportForward = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(forceTeleportForward)
		);



	std::shared_ptr<Setting<bool>> forceTeleportForwardIgnoreZ = std::make_shared<Setting<bool>> // ignore vertical component of players look angle
		(
			false,
			[](bool in) { return true; },
			nameof(forceTeleportForwardIgnoreZ)
		);



	std::shared_ptr<Setting<bool>> forceTeleportManual = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(forceTeleportManual)
		);

	std::shared_ptr<Setting<bool>> forceLaunchApplyToPlayer = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(forceLaunchApplyToPlayer)
		);

	std::shared_ptr<Setting<uint32_t>> forceLaunchCustomObject = std::make_shared<Setting<uint32_t>>
		(
			0xDEADB33F,
			[](uint32_t in) { return true; },
			nameof(forceLaunchCustomObject)
		);

	std::shared_ptr<Setting<SimpleMath::Vector3>> forceLaunchAbsoluteVec3 = std::make_shared<Setting<SimpleMath::Vector3>>
		(
			SimpleMath::Vector3{ 0.f, 0.f, 5.f },
			[](SimpleMath::Vector3 in) { return true; },
			nameof(forceLaunchAbsoluteVec3)
		);

	std::shared_ptr<Setting<SimpleMath::Vector3>> forceLaunchRelativeVec3 = std::make_shared<Setting<SimpleMath::Vector3>>
		(
			SimpleMath::Vector3{ 0.5f, 0.f, 0.f },
			[](SimpleMath::Vector3 in) { return true; },
			nameof(forceLaunchRelativeVec3)
		);


	std::shared_ptr<Setting<bool>> forceLaunchForward = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(forceLaunchForward)
		);

	std::shared_ptr<Setting<bool>> forceLaunchForwardIgnoreZ = std::make_shared<Setting<bool>> // ignore vertical component of players look angle
		(
			false,
			[](bool in) { return true; },
			nameof(forceLaunchForwardIgnoreZ)
		);

	std::shared_ptr<Setting<bool>> forceLaunchManual = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(forceLaunchManual)
		);



	std::shared_ptr<Setting<bool>> naturalCheckpointDisable = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(naturalCheckpointDisable)
		);

	std::shared_ptr<Setting<bool>> infiniteAmmoToggle = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(infiniteAmmoToggle)
		);

	std::shared_ptr<Setting<bool>> bottomlessClipToggle = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(bottomlessClipToggle)
		);

	std::shared_ptr<Setting<bool>> display2DInfoToggle = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(display2DInfoToggle)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowGameTick = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowGameTick)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowNextObjectDatum = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowNextObjectDatum)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowAggro = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowAggro)
		);

	std::shared_ptr<Setting<bool>> display2DInfoTrackPlayer = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoTrackPlayer)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerViewAngle= std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerViewAngle)
		);





	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerPosition = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerPosition)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerVelocity = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerVelocity)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerVelocityAbs = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerVelocityAbs)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerVelocityXY = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerVelocityXY)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerVelocityXYZ = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerVelocityXYZ)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerHealth = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerHealth)
		);


	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerRechargeCooldown = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerRechargeCooldown)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowPlayerVehicleHealth = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowPlayerVehicleHealth)
		);



	std::shared_ptr<Setting<bool>> display2DInfoTrackCustomObject = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoTrackCustomObject)
		);

	std::shared_ptr<Setting<uint32_t>> display2DInfoCustomObjectDatum = std::make_shared<Setting<uint32_t>>
		(
			0xDEADB33F,
			[](uint32_t in) { return true; },
			nameof(display2DInfoCustomObjectDatum)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityObjectType = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityObjectType)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityTagName = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityTagName)
		);


	std::shared_ptr<Setting<bool>> display2DInfoShowEntityPosition = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityPosition)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityVelocity = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityVelocity)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityVelocityAbs = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityVelocityAbs)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityVelocityXY = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityVelocityXY)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityVelocityXYZ = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityVelocityXYZ)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityHealth = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityHealth)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityRechargeCooldown = std::make_shared<Setting<bool>>
		(
			false,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityRechargeCooldown)
		);

	std::shared_ptr<Setting<bool>> display2DInfoShowEntityVehicleHealth = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoShowEntityVehicleHealth)
		);

	enum class Display2DInfoAnchorEnum
	{
		TopLeft,
		TopRight,
		BottomRight,
		BottomLeft
	};
	// actually an enum but stored as int
	std::shared_ptr<Setting<int>> display2DInfoAnchorCorner = std::make_shared<Setting<int>>
		(
			2, // 0 is top left, 1 is top right, 2 is bottom right, 3 is bottom left
			[](int in) { return in >= 0 && in <= 3; }, // within enum range
			nameof(display2DInfoAnchorCorner)
		);

	std::shared_ptr<Setting<SimpleMath::Vector2>> display2DInfoScreenOffset = std::make_shared<Setting<SimpleMath::Vector2>>
		(
			SimpleMath::Vector2{300, 300},
			[](SimpleMath::Vector2 in) { return in.x >= 0 && in.y >= 0; }, // no negative offsets
			nameof(display2DInfoScreenOffset)
		);

	std::shared_ptr<Setting<int>> display2DInfoFontSize = std::make_shared<Setting<int>>
		(
			16, 
			[](int in) { return in > 0 ; },
			nameof(display2DInfoFontSize)
		);

	std::shared_ptr<Setting<SimpleMath::Vector4>> display2DInfoFontColour = std::make_shared<Setting<SimpleMath::Vector4>>
		(
			SimpleMath::Vector4{1.00f, 0.60f, 0.25f, 1.00f}, // a nice orange colour that matches the rest of the gui
			[](SimpleMath::Vector4 in) { return in.x >= 0 && in.y >= 0 && in.z >= 0 && in.w >= 0 && in.x <= 1 && in.y <= 1 && in.z <= 1 && in.w <= 1; }, // range 0.f ... 1.f 
			nameof(display2DInfoFontColour)
		);

	std::shared_ptr<Setting<int>> display2DInfoFloatPrecision = std::make_shared<Setting<int>>
		(
			6,
			[](int in) { return in >= 0; },
			nameof(display2DInfoFloatPrecision)
		);

	std::shared_ptr<Setting<bool>> display2DInfoOutline = std::make_shared<Setting<bool>>
		(
			true,
			[](bool in) { return true; },
			nameof(display2DInfoOutline)
		);

	// settings that ought to be serialised/deserialised between HCM runs
	std::vector<std::shared_ptr<SerialisableSetting>> allSerialisableOptions
	{
		advanceTicksCount,
		injectionIgnoresChecksum,
		injectCheckpointForcesRevert,
		injectCheckpointLevelCheck,
		injectCheckpointVersionCheck,
			injectCheckpointDifficultyCheck,
		autonameCheckpoints,
		dumpCheckpointForcesSave,
			injectCoreForcesRevert,
		injectCoreLevelCheck,
		injectCoreVersionCheck,
			injectCoreDifficultyCheck,
		autonameCoresaves,
		dumpCoreForcesSave,
		invulnerabilityNPCToggle, 
		speedhackSetting, 
		GUIShowingFreesCursor, 
		GUIShowingBlocksInput, 
		GUIShowingPausesGame, 
		pauseAlsoBlocksInput,
		pauseAlsoFreesCursor,
		consoleCommandString,
		getObjectAddressDWORD,
		forceTeleportApplyToPlayer,
		forceTeleportCustomObject,
		forceTeleportAbsoluteVec3,
		forceTeleportRelativeVec3,
		forceTeleportForward,
		forceTeleportForwardIgnoreZ,
		forceTeleportManual,
		forceLaunchApplyToPlayer,
		forceLaunchCustomObject,
		forceLaunchAbsoluteVec3,
		forceLaunchRelativeVec3,
		forceLaunchForward,
		forceLaunchForwardIgnoreZ,
		forceLaunchManual,
		display2DInfoShowGameTick,
		display2DInfoShowAggro,
		display2DInfoShowNextObjectDatum,
		display2DInfoTrackPlayer,
		display2DInfoShowPlayerViewAngle,
		display2DInfoShowPlayerPosition,
		display2DInfoShowPlayerVelocity,
		display2DInfoShowPlayerVelocityAbs,
		display2DInfoShowPlayerVelocityXY,
		display2DInfoShowPlayerVelocityXYZ,
		display2DInfoShowPlayerHealth,
		display2DInfoShowPlayerRechargeCooldown,
		display2DInfoShowPlayerVehicleHealth,
		display2DInfoTrackCustomObject,
		display2DInfoCustomObjectDatum,
		display2DInfoShowEntityObjectType,
		display2DInfoShowEntityTagName,
		display2DInfoShowEntityPosition,
		display2DInfoShowEntityVelocity,
		display2DInfoShowEntityVelocityAbs,
		display2DInfoShowEntityVelocityXY,
		display2DInfoShowEntityVelocityXYZ,
		display2DInfoShowEntityHealth,
		display2DInfoShowEntityRechargeCooldown,
		display2DInfoShowEntityVehicleHealth,
		display2DInfoAnchorCorner,
		display2DInfoScreenOffset,
		display2DInfoFontSize,
		display2DInfoFontColour,
		display2DInfoFloatPrecision,
		display2DInfoOutline
	};
};

