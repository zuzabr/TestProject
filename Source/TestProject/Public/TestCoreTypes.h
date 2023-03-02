#pragma once
#include "TestCoreTypes.generated.h"

UENUM(BlueprintType)
enum class EMatchState : uint8
{
    None = 0,
    WaitingToStart,
    InProgress,
    Developers,
    Settings
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, EMatchState);
DECLARE_MULTICAST_DELEGATE(FOnGameStarted);
