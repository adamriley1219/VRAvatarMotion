// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Character.h"
#include "MyBlueCharacter.generated.h"

UCLASS()
class LIVINGAVATARS_API AMyBlueCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AMyBlueCharacter();

protected:
	// Called when the game starts or when spawned
	int frameCounter = 0;
	int scenesCaptured = 0;
	std::ofstream outFile;
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		FTransform scenePos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Hip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Spine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Spine1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Spine2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Neck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform Head;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LShoulder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LForeArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LHandTrack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RShoulder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RForeArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RHandTrack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LUpLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform LFoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RUpLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyBlueCharacter)
		 FTransform RFoot;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category="isMoving")
	bool isMoving();
	UFUNCTION(BlueprintCallable)
		void StartRecording();
	UFUNCTION(BlueprintCallable)
		void EndRecording();
	void CalcMotionCap();
	UFUNCTION(BlueprintCallable)
		void TakeSnapshot();
};
