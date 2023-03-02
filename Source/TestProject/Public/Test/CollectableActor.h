// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test/InteractionInterface.h"
#include "CollectableActor.generated.h"

UCLASS()
class TESTPROJECT_API ACollectableActor : public AActor, public IInteractionInterface
{
    GENERATED_BODY()

public:

    ACollectableActor();

protected:

    virtual void BeginPlay() override;
    virtual void Interact() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* ItemMesh;


};
