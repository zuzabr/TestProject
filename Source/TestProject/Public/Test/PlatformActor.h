// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformActor.generated.h"

class UBoxComponent;
class UWidgetComponent;

UCLASS()
class TESTPROJECT_API APlatformActor : public AActor
{
    GENERATED_BODY()

public:
  
    APlatformActor();

protected:
    virtual void BeginPlay() override;
    
private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Platform;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BoxCollission;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UWidgetComponent* PlatformWidget;


    UFUNCTION()
    void BeginPress(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void StopPress(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
