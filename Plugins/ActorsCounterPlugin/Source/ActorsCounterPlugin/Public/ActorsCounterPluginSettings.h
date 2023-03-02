#pragma once

#include "Engine/DeveloperSettings.h"
#include "ActorsCounterPluginSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Actors Counter Plugin Settings"))
class ACTORSCOUNTERPLUGIN_API UActorsCounterPluginSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UPROPERTY(Config, EditAnywhere, Category = "Main")
    FString LogMessage;

    UPROPERTY(Config, EditAnywhere, Category = "Main")
    TSubclassOf<AActor> ActorClass;

    UPROPERTY(Config, EditAnywhere, Category = "Main")
    int32 MaxNumberOfActors = 1000;
};