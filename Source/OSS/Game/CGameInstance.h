
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/CMenuInterface.h"
#include "CGameInstance.generated.h"

class UUserWidget;
class UCMainMenu;

UCLASS()
class OSS_API UCGameInstance : public UGameInstance, public ICMenuInterface
{
	GENERATED_BODY()

public:
	UCGameInstance();
	void Init();
	
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& InAddress);

	UFUNCTION(BlueprintCallable, Exec)
	void LoadMainMenu();

private:
	TSubclassOf<UUserWidget> MainMenuClass;
	UCMainMenu* MainMenu;
};