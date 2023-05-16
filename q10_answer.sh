#!/bin/bash

# Create directories
mkdir -p final/src
mkdir -p final/data/main
mkdir -p final/data/backup
mkdir -p final/config

# Move files
mv main.cpp final/src/
mv header.h final/src/
mv mainDB.db final/data/main/
mv backupDB.db final/data/backup/
mv config.yml final/config/
mv README.MD final/

# Create empty files
touch final/data/main/.gitkeep
touch final/data/backup/.gitkeep
touch final/src/.gitkeep
touch final/config/.gitkeep
touch final/.gitkeep

echo "Directories created and files moved successfully."
