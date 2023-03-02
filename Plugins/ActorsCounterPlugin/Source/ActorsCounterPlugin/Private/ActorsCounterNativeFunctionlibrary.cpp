#include "ActorsCounterNativeFunctionLibrary.h"
#include "ActorsCounterPluginSettings.h"
#include "Kismet/GameplayStatics.h"

int32 UActorsCounterNativeFunctionLibrary::CountActorsOnLevel(const AActor* Actor)
{
    FString Message = GetDefault<UActorsCounterPluginSettings>()->LogMessage;
    

    if (Actor ==nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor was not set"));
        return 0;
    }

    UE_LOG(LogTemp, Log, TEXT("%s"), *Message);

    auto NeededClass = GetDefault<UActorsCounterPluginSettings>()->ActorClass;
    auto Name = NeededClass.GetDefaultObject()->GetFName();

    TArray<AActor*> OutActors;
    UGameplayStatics::GetAllActorsOfClass(Actor, NeededClass, OutActors);

    if(OutActors.Num()>=GetDefault<UActorsCounterPluginSettings>()->MaxNumberOfActors)
    {
        
        UE_LOG(LogTemp, Display, TEXT("There are max number of %s actors on level"), *(Name.ToString()));
        return GetDefault<UActorsCounterPluginSettings>()->MaxNumberOfActors;
       
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("The %s number is %i"),*(Name.ToString()), OutActors.Num());
        return OutActors.Num();
    }


}
