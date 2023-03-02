// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoToMenuWidget.generated.h"

class UButton;

UCLASS()
class TESTPROJECT_API UGoToMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton* GoToMenuButton;

private:
    UFUNCTION()
    void OnGoToMenu();
};
