cmake_minimum_required(VERSION 3.10)

project(MyProject C)

# Derlenecek dosyalar ve target oluştur
add_executable(main main.c src/stdextended.c)

# Include path (main target’ına ekle)
target_include_directories(main PRIVATE Include)