// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Test/Menu/MenuGameMode.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnPressed.AddDynamic(this, &UMainMenuWidget::OnStartGame);
    }

    if (SettingsButton)
    {
        SettingsButton->OnPressed.AddDynamic(this, &UMainMenuWidget::OnOpenSettingsMenu);
    }

    if (DevelopersButton)
    {
        DevelopersButton->OnPressed.AddDynamic(this, &UMainMenuWidget::OnOpenDevelopersMenu);
    }
}

void UMainMenuWidget::OnStartGame()
{
// Better not to use hard way, but for test, it's ok   
    UGameplayStatics::OpenLevel(this, "lvl_Test");
}

void UMainMenuWidget::OnOpenSettingsMenu()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
    const auto GameMode = Cast<AMenuGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        GameMode->OpenSettingsMenu();
    }
}

void UMainMenuWidget::OnOpenDevelopersMenu()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
    const auto GameMode = Cast<AMenuGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        GameMode->OpenDevelopersMenu();
    }
}
