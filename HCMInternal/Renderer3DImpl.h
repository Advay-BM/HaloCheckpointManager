#pragma once
#include "pch.h"
#include "DIContainer.h"
#include "IRenderer3D.h"
#include "GameState.h"
#include "IMessagesGUI.h"
#include "RuntimeExceptionHandler.h"
#include "IMCCStateHook.h"
#include "GetGameCameraData.h"
#include "IMakeOrGetCheat.h"
#include "SettingsStateAndEvents.h"

// impl in .cpp
template<GameState::Value mGame>
class Renderer3DImpl : public IRenderer3D
{
private:
	// data
	DirectX::SimpleMath::Matrix viewMatrix;
	DirectX::SimpleMath::Matrix projectionMatrix;
	SimpleMath::Vector2 screenSize;

	// injected services
	std::weak_ptr<GetGameCameraData> getGameCameraDataWeak;
	std::weak_ptr<SettingsStateAndEvents> settingsWeak;
	std::weak_ptr<IMCCStateHook> mccStateHookWeak;
	std::weak_ptr<IMessagesGUI> messagesGUIWeak;
	std::shared_ptr<RuntimeExceptionHandler> runtimeExceptions;

	// funcs
	SimpleMath::Vector3 worldToScreen(SimpleMath::Vector3 world);
	virtual void updateCameraData(const SimpleMath::Vector2& screensize);
	friend class Render3DEventProvider;
public:
	virtual void draw3DText(const std::string& text, const SimpleMath::Vector3& targetPosition, const SimpleMath::Vector4& textColor);
	Renderer3DImpl(GameState game, IDIContainer& dicon);
	~Renderer3DImpl();
};