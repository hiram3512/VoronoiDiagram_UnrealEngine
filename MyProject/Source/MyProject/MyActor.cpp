#include "MyActor.h"
#include "VoronoiDiagram.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::Process()
{
	TArray<FIntPoint> Points;
	for (int i = 0; i < PointCount; i++)
	{
		int X = FMath::RandRange(0, Width - 1);
		int Y = FMath::RandRange(0, Height - 1);
		Points.Add(FIntPoint(X, Y));
		if (bShowPoint)
		{
			FVector Pos = FVector(0, X, Y);
			UKismetSystemLibrary::DrawDebugBox(this, Pos, FVector(1, 1, 1),
				FColor::White, FRotator::ZeroRotator, DisplayTime);
		}
	}
	TSharedPtr<FVoronoiDiagram> VoronoiDiagram(new FVoronoiDiagram(FIntRect(0, 0, Width, Height)));
	VoronoiDiagram->AddPoints(Points);
	VoronoiDiagram->GenerateSites(RelaxationCycles);
	for (int32 i = 0; i < VoronoiDiagram->GeneratedSites.Num(); ++i)
	{
		FVoronoiDiagramGeneratedSite& VoronoiCell = VoronoiDiagram->GeneratedSites[i];
		for (int x = 1; x < VoronoiCell.Vertices.Num(); x++)
		{
			FVector Start = FVector(0, VoronoiCell.Vertices[x - 1].X, VoronoiCell.Vertices[x - 1].Y);
			FVector End = FVector(0, VoronoiCell.Vertices[x].X, VoronoiCell.Vertices[x].Y);
			UKismetSystemLibrary::DrawDebugLine(this, Start, End,
			                                    FColor::MakeRandomColor(), DisplayTime);
			if (x == VoronoiCell.Vertices.Num() - 1)
			{
				Start = FVector(0, VoronoiCell.Vertices[x].X, VoronoiCell.Vertices[x].Y);
				End = FVector(0, VoronoiCell.Vertices[0].X, VoronoiCell.Vertices[0].Y);
				UKismetSystemLibrary::DrawDebugLine(this, Start, End,
				                                    FColor::MakeRandomColor(), DisplayTime);
			}
		}
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
