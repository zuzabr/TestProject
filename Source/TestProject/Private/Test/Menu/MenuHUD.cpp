// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/Menu/MenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Test/Menu/MenuGameMode.h"

void AMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    GameWidgets.Add(EMatchState::WaitingToStart, CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass));
    GameWidgets.Add(EMatchState::Settings, CreateWidget<UUserWidget>(GetWorld(), SettingsWidgetClass));
    GameWidgets.Add(EMatchState::Developers, CreateWidget<UUserWidget>(GetWorld(), DevelopersWidgetClass));

    for (auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget) continue;

        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<AMenuGameMode>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &AMenuHUD::OnMatchStateChanged);
        }
    }
}

void AMenuHUD::OnMatchStateChanged(EMatchState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
    }

    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    }
}
