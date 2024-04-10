﻿// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "CommonUI/Public/CommonActivatableWidget.h"
#include "Input/CommonInputMode.h"
#include "CommonActivatableWidgetFixed.generated.h"

UENUM(BlueprintType)
enum class EWidgetInputMode : uint8
{
	Default,
	GameAndMenu,
	Game,
	Menu
};

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API UCommonActivatableWidgetFixed : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	//~UCommonActivatableWidget interface
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override
	{
		switch (InputConfig)
		{
		case EWidgetInputMode::GameAndMenu:
			return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
		case EWidgetInputMode::Game:
			return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
		case EWidgetInputMode::Menu:
			return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
		case EWidgetInputMode::Default:
		default:
			return TOptional<FUIInputConfig>();
		}
	}

	//~End of UCommonActivatableWidget interface

protected:

	/** The desired input mode to use while this UI is activated, for example do you want key presses to still reach the game/player controller? */
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EWidgetInputMode InputConfig = EWidgetInputMode::Default;

	/** The desired mouse behavior when the game gets input. */
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};
