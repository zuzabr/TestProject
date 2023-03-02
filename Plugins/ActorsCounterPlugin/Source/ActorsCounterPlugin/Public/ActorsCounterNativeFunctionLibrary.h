#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorsCounterNativeFunctionLibrary.generated.h"

UCLASS()
class ACTORSCOUNTERPLUGIN_API UActorsCounterNativeFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "ActorsCounter")
    static int32 CountActorsOnLevel(const AActor* Actor);
};
