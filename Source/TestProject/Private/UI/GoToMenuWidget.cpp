// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/GoToMenuWidget.h"
#include "Components/Button.h"
#include "Test/Menu/MenuGameMode.h"
#include "Kismet/GameplayStatics.h"

void UGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GoToMenuButton)
    {
        GoToMenuButton->OnClicked.AddDynamic(this, &UGoToMenuWidget::OnGoToMenu);
    }
}

void UGoToMenuWidget::OnGoToMenu()
{
  

    if (UGameplayStatics::GetCurrentLevelName(this) == "lvl_Test")
    {
        if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
        const auto GameMode = Cast<AMenuGameMode>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OpenMainMenu();
        }
    }
    else
    {
        UGameplayStatics::OpenLevel(this, "lvl_Menu");
    }

    
}
