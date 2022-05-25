#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	UFUNCTION(BlueprintCallable)
	void Process();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	int Width = 100;

	UPROPERTY(EditAnywhere)
	int Height = 100;

	UPROPERTY(EditAnywhere)
	int PointCount = 10;

	UPROPERTY(EditAnywhere)
	int RelaxationCycles = 2;

	UPROPERTY(EditAnywhere)
	float DisplayTime = 5;

	UPROPERTY(EditAnywhere)
	bool bShowPoint = true;
};
