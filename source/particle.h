#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "scene.h"

#include <vector>
#include <functional>

#include <3ds/types.h>

const u8 STILL = 1;
const u8 FLOATING = 2;
const u8 BURNABLE = 4;
const u8 BURNS_TO_EMBER = 8;
const u8 SELECTABLE = 16;
const u8 DATA = 32;
const u8 NO_DRAW = 64;

class Scene;

class ParticleType {
public:
    // Still
    static ParticleType* NOTHING;
    static ParticleType* WALL;
    static ParticleType* IRONWALL;
    static ParticleType* TORCH;
    static ParticleType* STOVE;
    static ParticleType* ICE;
    static ParticleType* RUST;
    static ParticleType* EMBER;
    static ParticleType* PLANT;
    static ParticleType* VOID;

    // Spouts
    static ParticleType* WATERSPOUT;
    static ParticleType* SANDSPOUT;
    static ParticleType* SALTSPOUT;
    static ParticleType* OILSPOUT;

    // Elemental
    static ParticleType* WATER;
    static ParticleType* DIRT;
    static ParticleType* SALT;
    static ParticleType* OIL;
    static ParticleType* SAND;
    static ParticleType* ASH;

    // Combined
    static ParticleType* SALTWATER;
    static ParticleType* MUD;
    static ParticleType* ACID;

    // Floating
    static ParticleType* STEAM;
    static ParticleType* FIRE;

    // Electricity
    static ParticleType* ELECTRICITY;

    // Explosive
    static ParticleType* EXPLOSION;
    static ParticleType* GUNPOWDER;

    static std::vector<ParticleType*>* TYPES;

    static void InitParticles();

    ParticleType(const char* name, u8 r, u8 g, u8 b, u8 flags) {
        this->name = name;
        this->r = r;
        this->g = g;
        this->b = b;
        this->flags = flags;
    }

    ParticleType(const char* name, u8 r, u8 g, u8 b) : ParticleType(name, r, g, b, 0) {}

    const char* GetName() {
        return this->name;
    }

    u8 GetRed() {
        return this->r;
    }

    u8 GetGreen() {
        return this->g;
    }

    u8 GetBlue() {
        return this->b;
    }

    bool IsStill() {
        return CheckFlag(STILL);
    }

    bool IsFloating() {
        return CheckFlag(FLOATING);
    }

    bool IsBurnable() {
        return CheckFlag(BURNABLE);
    }

    bool BurnsToEmber() {
        return CheckFlag(BURNS_TO_EMBER);
    }

    bool IsSelectable() {
        return CheckFlag(SELECTABLE);
    }

    bool HasData() {
        return CheckFlag(DATA);
    }

    bool IsDrawn() {
        return !CheckFlag(NO_DRAW);
    }

    std::function<void(Scene*, int, int)> GetPhysics() {
        return this->physics;
    }

    void SetPhysics(std::function<void(Scene*, int, int)> physics) {
        this->physics = physics;
    }
private:
    const char* name;
    u8 r;
    u8 g;
    u8 b;
    u8 flags;
    std::function<void(Scene*, int, int)> physics = NULL;

    bool CheckFlag(u8 flag) {
        return (this->flags & flag) == flag;
    }
};

#endif