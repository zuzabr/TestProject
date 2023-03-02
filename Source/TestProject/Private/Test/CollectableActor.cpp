// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/CollectableActor.h"


ACollectableActor::ACollectableActor()
{
    
    PrimaryActorTick.bCanEverTick = false;

    ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item Mesh");
    ItemMesh->SetupAttachment(GetRootComponent());
}


void ACollectableActor::BeginPlay()
{
    Super::BeginPlay();
}

void ACollectableActor::Interact() 
{
    Destroy();
}

