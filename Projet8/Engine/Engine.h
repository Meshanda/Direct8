﻿#pragma once

class Component;
class Profiler;
class Scene;

class Engine
{

public:
	Engine(HWND hWnd);
	~Engine();

	void Play();
	void Stop();
	void Pause();
	void Step();

	void LoadScene(Scene* scene);

private:
	HWND _window = nullptr;

	Profiler* _profiler = nullptr;
	Scene* _scene = nullptr;

	bool _isPlaying = false;

	void InitLight();
	void InitD3D();

	void NewFrame();
	void RunFrame();

	void Start();
	void Update(float runTime, float deltaTime);
	void Collision();

private:
	list<Component*> _startedComponents;

};
