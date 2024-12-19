#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CMovingPlatform_Trigger.generated.h"

class UBoxComponent;
class ACMovingPlatform;

UCLASS()
class OSS_API ACMovingPlatform_Trigger : public AActor
{
	GENERATED_BODY()
	
public:	
	ACMovingPlatform_Trigger();

private:
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, Category = "Platform")
	TArray<ACMovingPlatform*> PlatformToTrigger;
};