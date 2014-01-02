#include "MalusEntity.h"

MalusEntity::MalusEntity(const std::string& sprite,
                         unsigned char minimalSpeed,
                         short points) : ScoringEntity(sprite,
                                                       minimalSpeed,
                                                       points) {}

/** @brief  Destroy a BonusEntity. */
MalusEntity::~MalusEntity() {}


void MalusEntity::additionnalStuffOnBreak() {}
