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

	void Input();
	void Start();
	void Update(float runTime, float deltaTime);

private:
	list<Component*> _startedComponents;

};
