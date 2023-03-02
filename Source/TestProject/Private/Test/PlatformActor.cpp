// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/PlatformActor.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "TestProjectCharacter.h"

// Sets default values
APlatformActor::APlatformActor()
{

    PrimaryActorTick.bCanEverTick = false;

    Platform = CreateDefaultSubobject<UStaticMeshComponent>("Platform");
    SetRootComponent(Platform);

    BoxCollission = CreateDefaultSubobject<UBoxComponent>("Box");
    BoxCollission->SetupAttachment(Platform);

    PlatformWidget = CreateDefaultSubobject<UWidgetComponent>("Widget");
    PlatformWidget->SetupAttachment(Platform);
    PlatformWidget->SetVisibility(false);
}

// Called when the game starts or when spawned
void APlatformActor::BeginPlay()
{
    Super::BeginPlay();

    check(BoxCollission);
    BoxCollission->OnComponentBeginOverlap.AddDynamic(this, &APlatformActor::BeginPress);
    BoxCollission->OnComponentEndOverlap.AddDynamic(this, &APlatformActor::StopPress);
}

void APlatformActor::BeginPress(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (Cast<ATestProjectCharacter>(OtherActor))
    {
        PlatformWidget->SetVisibility(true);
    }
    
}

void APlatformActor::StopPress(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (Cast<ATestProjectCharacter>(OtherActor))
    {
        PlatformWidget->SetVisibility(false);
    }
}




