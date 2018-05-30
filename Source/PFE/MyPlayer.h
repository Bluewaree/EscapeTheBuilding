// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class PFE_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	    class USpringArmComponent* CameraBoom;

	    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	    class UCameraComponent* FollowCamera;


public:
	AMyPlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	
	bool ready = false;
	bool Interaction = false;

	FString number = FString("");
	FString numberTest = FString("");
protected:

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);



	void Press0();
	void Press1();
	void Press2();
	void Press3();
	void Press4();
	void Press5();
	void Press6();
	void Press7();
	void Press8();
	void Press9();
	void InteractBegin();
	void InteractEnd();


	void BeginEnter();
	void EndEnter();
protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


public:

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	
	
};
