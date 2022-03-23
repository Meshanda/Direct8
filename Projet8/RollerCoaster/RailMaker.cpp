#include "RailMaker.h"


void RailMaker::Update()
{
	

	/* generate secret number between 1 and 10: */
	
	float farestCubedist = 0;
	if (!cubes.empty())
		farestCubedist = Utils::DistanceWithOutSquareRoot(transform->GetPosition(), cubes.back()->transform->GetPosition());
	if (farestCubedist < (_maxDistance - _spaceBetween) * (_maxDistance - _spaceBetween))
	{
		float random = rand()%100;
		if (random <= 2.5f)
		{
			Turn(-90);
		}
		else if (random <= 5)
		{
			Turn(90);
		}
		else
		{
			MoveForward();
		}
		Utils::Println(random);
	}
}

void RailMaker::Start()
{
	//MoveForward();
	srand(time(0));
}

void RailMaker::Turn(float rotate)
{
	D3DXVECTOR3 position = transform->GetPosition();
	Cube* farestCube = nullptr;
	GameObject* box = nullptr;
	for(int i = 0 ; i < _step; i++)
	{
		box = new GameObject();
		box->AddComponent(new Cube());
		(Cube*)box->GetComponent(NAMEOF(Cube));
		if (!cubes.empty())
		{
			
			box->transform->SetQuaternion(cubes.back()->transform->GetQuaternion());
		}
		D3DXVECTOR3  vector;
		if (!cubes.empty())
			vector = cubes.back()->transform->GetPosition() + cubes.back()->transform->GetForward() * _spaceBetween ;
		else
			vector = transform->GetPosition() + transform->GetForward() * _spaceBetween;
		vector.y = -4;
		//vector.y += _spaceBetween * i;
		box->transform->SetPosition(vector);
		box->transform->RotateYaw((rotate / _step));
		//box->transform->RotatePitch((rotate / _step));
		
		SceneManager::Instantiate(box);
		cubes.push_back((Cube*)box->GetComponent(NAMEOF(Cube)));
	}

	
}

void RailMaker::MoveForward()
{
	float farestCubedist = 0;
	D3DXVECTOR3 position = transform->GetPosition();
	Cube* farestCube = nullptr;
	GameObject* box = nullptr;
	Cube* MovingRail = nullptr;
	if (!cubes.empty())
		farestCubedist = Utils::DistanceWithOutSquareRoot(position, cubes.back()->transform->GetPosition());
	else
	{
		farestCubedist = 0;
	}
	if (farestCubedist < (_maxDistance - _spaceBetween) * (_maxDistance - _spaceBetween))
	{
		if (box == nullptr)
		{
			box = new GameObject();
			box->AddComponent(new Cube());
			(Cube*)box->GetComponent(NAMEOF(Cube));
		}

		D3DXVECTOR3  vector;
		if (!cubes.empty())
		{
			box->transform->SetQuaternion(cubes.back()->transform->GetQuaternion());
			vector = cubes.back()->transform->GetPosition() + cubes.back()->transform->GetForward() * _spaceBetween;
		}
		else
		{
			vector = transform->GetPosition() + transform->GetForward() * _spaceBetween;
		}
		vector.y = -4;

		box->transform->SetPosition(vector);
		SceneManager::Instantiate(box);
		cubes.push_back((Cube*)box->GetComponent(NAMEOF(Cube)));

	}

	Cube* firstCreated = cubes.front();
	if (cubes.front()->transform->GetPosition().z < transform->GetPosition().z)
	{

		cubes.pop_front();
	}
}