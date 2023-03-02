
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test/InteractionInterface.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class TESTPROJECT_API ADoorActor : public AActor, public IInteractionInterface
{
    GENERATED_BODY()

public:
    ADoorActor();
    virtual void Interact() override;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    FTimeline Timeline;
    UPROPERTY(EditAnywhere, Category = "Door Settings")
    UCurveFloat* CurveFloat;
    UPROPERTY(EditAnywhere, Category = "Door Settings")
    float DoorRotateAngle = 90.f;

private:

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* DoorFrame;
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Door;

    bool bClosed = true;

    UFUNCTION()
    void OpenDoor(float Value);
    
};
