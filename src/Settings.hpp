#pragma once
#include <cstdint>
#include <iostream>

#include <Raylib/raylib.h>
#include <Raylib/raymath.h>

#include <box3d/box3d.h>

class Settings
{
public :
    static Settings instance;

    static const int           seed;
    static const std::uint32_t width;
    static const std::uint32_t height;

    //Camera and controls
    static const float d_zoomScale;
    static const float d_cameraSpeed;
    static const float d_sensitivity;
    static const float d_observationDist;
    static const float d_fov;
    static bool  debugMode;

    static const float d_animSpeed;

    //Physics
    static const b3Vec3 g;
    static const int subStepCount;
    static       int maxHullVertexCount;

    //UI
    static const Vector2 menuButtonSize;
    static bool          showPause;
    static bool          showOptions;

private :
    Settings();
};