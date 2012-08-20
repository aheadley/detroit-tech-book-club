#!/bin/bash

for f in "$@"; do
    sed -i -r 's/^[0-9]{1}  //' "$f" && \
    sed -i -r 's/^[0-9]{2}  //' "$f" && \
    sed -i -r 's/^[0-9]{3}  //' "$f" && \
    sed -i -r 's/^[0-9]{1,3}$//' "$f"
done

