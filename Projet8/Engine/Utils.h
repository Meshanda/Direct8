#pragma once

class Utils final
{

public:
	Utils() = delete;

	static void PrintError(string file, int line, LPCWSTR value);
	static void Println(LPCWSTR value);
	static void Println(wstring value);
	static void Println(string value);
	static void Println(int value);
	static void Println(unsigned value);
	static void Println(long value);
	static void Println(unsigned long value);
	static void Println(long long value);
	static void Println(unsigned long long value);
	static void Println(double value);
	static void Println(float value);
	static void Println(long double value);

	template<typename T>
	static bool Contains(const list<T*>* list, const T* value);
	template<typename T>
	static bool Contains(const list<T>* list, const T value);

	template<typename T>
	static void DeleteList(list<T*> listIn);
	template <typename K, typename V>
	static void DeleteMap(map<K*, V*> mapIn);
	template <typename K, typename V>
	static void DeleteMapFirst(map<K*, V> mapIn);
	template <typename K, typename V>
	static void DeleteMapSecond(map<K, V*> mapIn);

	static float DistanceWithOutSquareRoot(D3DXVECTOR3 a, D3DXVECTOR3 b);
	static float Distance(D3DXVECTOR3 a, D3DXVECTOR3 b) ;
	static D3DXVECTOR4 GetVec4FromQuat(D3DXQUATERNION* q);
	static D3DXQUATERNION GetQuatFromVec4( D3DXVECTOR4* q);
	static D3DXQUATERNION SLERP(const D3DXQUATERNION* a, const D3DXQUATERNION* b, const float t);
};

#include "Utils.tpp"
