#ifndef BLOCKTYPE_H_
#define BLOCKTYPE_H_

#include <string>

class BlockType
{
    private:
        std::string name;
        bool solid;
        bool translucent;
        bool opaque;
        int explodePower;
        int hardness;

    public:
        BlockType(const char* name_, bool solid_, bool translucent_, bool opaque_, int explodePower_, int hardness_):
            name(name_), solid(solid_), translucent(translucent_), opaque(opaque_), explodePower(explodePower_), hardness(hardness_)
        {
        }
        
        // Internal block name
        std::string getName() const;
        // Is solid block
        bool isSolid() const;
        // Transparency determines how it will rendered
        bool isTranslucent() const;
        // Opaque means it blocks light 
        bool isOpaque() const;
        // Explode power, if it isn't a explosive set this to 0
        int getExplodePower() const;
        // Hardness
        int getHardness() const;

};

#endif // !BLOCKTYPE_H_