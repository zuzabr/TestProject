// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/LightActor.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "TestProjectCharacter.h"

// Sets default values
ALightActor::ALightActor()
{

    PrimaryActorTick.bCanEverTick = false;

    LightCollission = CreateDefaultSubobject<USphereComponent>("Sphere");
    SetRootComponent(LightCollission);
    LightCollission->SetSphereRadius(200.0f);

    Light = CreateDefaultSubobject<UPointLightComponent>("Light");
    Light->SetupAttachment(LightCollission);
    Light->SetIntensity(0.f);
    
    

    
}

void ALightActor::BeginPlay()
{
    Super::BeginPlay();

    check(LightCollission);
    LightCollission->OnComponentBeginOverlap.AddDynamic(this, &ALightActor::TurnOnLight);
    LightCollission->OnComponentEndOverlap.AddDynamic(this, &ALightActor::TurnOff);
}

void ALightActor::TurnOnLight(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (Cast<ATestProjectCharacter>(OtherActor))
    {
        Light->SetIntensity(10000.f);
    }
    
}

void ALightActor::TurnOff(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (Cast<ATestProjectCharacter>(OtherActor))
    {
        Light->SetIntensity(0.f);
    }
}
