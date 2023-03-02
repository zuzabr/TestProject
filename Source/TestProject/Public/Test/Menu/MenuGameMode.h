// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestCoreTypes.h"
#include "MenuGameMode.generated.h"


UCLASS()
class TESTPROJECT_API AMenuGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AMenuGameMode();

    virtual void StartPlay() override;

    FOnMatchStateChangedSignature OnMatchStateChanged;
    void OpenSettingsMenu();
    void OpenDevelopersMenu();
    void OpenMainMenu();

private:
    EMatchState MatchState = EMatchState::None;
    void SetMatchState(EMatchState State);
};
