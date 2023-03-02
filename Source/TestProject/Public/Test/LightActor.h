// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightActor.generated.h"

class USphereComponent;
class UPointLightComponent;

UCLASS()
class TESTPROJECT_API ALightActor : public AActor
{
    GENERATED_BODY()

public:
    ALightActor();

protected:
    virtual void BeginPlay() override;


    UPROPERTY(EditAnywhere, Category = "Components")
    UPointLightComponent* Light;

    UPROPERTY(EditAnywhere, Category = "Components")
    USphereComponent* LightCollission;


    UFUNCTION()
    void TurnOnLight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void TurnOff(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
