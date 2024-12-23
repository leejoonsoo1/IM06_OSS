#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/CMenuInterface.h"
#include "CMainMenu.generated.h"

class UButton;
class UWidgetSwitcher;
class UEditableTextBox;

UCLASS()
class OSS_API UCMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void OpenJoinMenu();


public:
	void SetOwningInstance(ICMenuInterface* InInstance);

	void Startup();
	void Shutdown();

private:
	// MainMenu
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	// MenuSiwtcher
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	// Join Menu
	UPROPERTY(meta = (BindWidget))
	UButton* CancelJoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmJoinButton;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPAddressField;

private:
	ICMenuInterface* OwningInstance;
};
