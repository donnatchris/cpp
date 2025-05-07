#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

file1="$1"
file2="$2"

# Supprimer les timestamps et comparer les lignes
diff <(sed 's/^\[[^]]*\] //' "$file1") <(sed 's/^\[[^]]*\] //' "$file2")

if [ $? -eq 0 ]; then
    echo "✅ Les fichiers sont identiques (hors timestamp)"
else
    echo "❌ Les fichiers sont différents"
fi

