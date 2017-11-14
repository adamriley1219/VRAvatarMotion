// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGuyCCharacter.h"


// Sets default values
ATestingGuyCCharacter::ATestingGuyCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingGuyCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestingGuyCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalcMotionCap();
}

// Called to bind functionality to input
void ATestingGuyCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATestingGuyCCharacter::CalcMotionCap()
{
	//std::vector<USceneComponent> sceneComps;
	//FString fstring = FindComponentByClass<USceneComponent>()->GetName();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO WORLD!"));
	for (UActorComponent *const component : GetComponents())
	{
		if (component->GetName().Equals("Scene"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			scenePos = temp->GetComponentTransform();
		}
		else if (component->GetName().Equals("HipTracker"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Hip = temp->GetComponentTransform();

			/*FQuat rotation = Hip.GetRotation();
			FRotator theRot = rotation.Rotator();
			theRot.Roll += 90;
			FQuat res(theRot);
			Hip.SetRotation(res);*/

			/*FVector pos = Hip.GetLocation();
			pos[0] -= 15;
			Hip.SetLocation(pos);*/
		}
		else if (component->GetName().Equals("Camera"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Head = temp->GetComponentTransform();

			//	FQuat rotation = Head.GetRotation();
			//	FVector location = Head.GetLocation();
			//	FRotator theRot = rotation.Rotator();
			//	theRot.Roll += 90;
			//	FQuat res(theRot);
			//	Head.SetRotation(res);

			/*	float Xa = rotation.X;
			float Ya = rotation.Y;
			float Za = rotation.Z;

			rotation.X = -Za;
			rotation.Y = -Ya;
			rotation.Z = Xa;

			*///	FRotator theRot = rotation.Rotator();

			//	location.X = 5;
			//	location.Y = 5;
			//	location.Z = 5;


			//theRot.Yaw += -90;
			//theRot.Pitch += 90;
			//theRot.Roll += 90;
			//	Head.SetRotation(FQuat(theRot));
			//	Head.SetLocation(location);
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Head.ToString());
		}
		else if (component->GetName().Equals("MotionController_l"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			LHandTrack = temp->GetComponentTransform();


			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO, Creating Left Hand!"));

		}
		else if (component->GetName().Equals("MotionController_r"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			RHandTrack = temp->GetComponentTransform();


		}
	}


	std::ofstream outFile;

	outFile.open("../../../../../../Users/adamr/Desktop/test.txt");
	outFile << "Hello World!!!" << std::endl
		<< "Hip:				" << TCHAR_TO_UTF8(*Hip.ToString()) << std::endl
		<< "Head:				" << TCHAR_TO_UTF8(*Head.ToString()) << std::endl
		<< "LeftHand:			" << TCHAR_TO_UTF8(*LHandTrack.ToString()) << std::endl
		<< "RightHand:			" << TCHAR_TO_UTF8(*RHandTrack.ToString()) << std::endl
		<< "Location of Scene:	" << TCHAR_TO_UTF8(*scenePos.ToString()) << std::endl;
	outFile.close();

	Spine; // .SetComponents(FQuat Rotation, FVector Translation, FVector Scale)
	Spine1;
	Spine2;
	Neck;
	LShoulder;
	LArm;
	LForeArm;
	RShoulder;
	RArm;
	RForeArm;
	LUpLeg;
	LLeg;
	LFoot;
	RUpLeg;
	RLeg;
	RFoot;
}
