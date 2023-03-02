// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/Menu/MenuGameMode.h"
#include "Test/Menu/MenuController.h"
#include "Test/Menu/MenuHUD.h"

AMenuGameMode::AMenuGameMode()
{
    HUDClass = AMenuHUD::StaticClass();
    PlayerControllerClass = AMenuController::StaticClass();
}

void AMenuGameMode::StartPlay()
{
    Super::StartPlay();
    OpenMainMenu();
}

void AMenuGameMode::OpenSettingsMenu()
{
    SetMatchState(EMatchState::Settings);
}

void AMenuGameMode::OpenDevelopersMenu()
{
    SetMatchState(EMatchState::Developers);
}

void AMenuGameMode::OpenMainMenu()
{
    SetMatchState(EMatchState::WaitingToStart);
}

void AMenuGameMode::SetMatchState(EMatchState State)
{
    if (MatchState == State) return;
    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}