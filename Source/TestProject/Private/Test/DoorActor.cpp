// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/DoorActor.h"



ADoorActor::ADoorActor()
{
    PrimaryActorTick.bCanEverTick = true;

    DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>("DoorFrame");
    SetRootComponent(DoorFrame);

    Door = CreateDefaultSubobject<UStaticMeshComponent>("Door");
    Door->SetupAttachment(DoorFrame);
}

void ADoorActor::Interact() 
{
    if (bClosed)
    {
        Timeline.Play();
    }
    else
    {
        Timeline.Reverse();
    }

    bClosed = !bClosed;
}


void ADoorActor::BeginPlay()
{
    Super::BeginPlay();

    if (CurveFloat)
    {
        FOnTimelineFloat TimeLineProgress;
        TimeLineProgress.BindDynamic(this, &ADoorActor::OpenDoor);
        Timeline.AddInterpFloat(CurveFloat, TimeLineProgress);
    }
}

void ADoorActor::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

    Timeline.TickTimeline(DeltaTime);
}

void ADoorActor::OpenDoor(float Value)
{
    FRotator Rotator = FRotator(0.f, DoorRotateAngle * Value, 0.f);
    Door->SetRelativeRotation(Rotator);
}
