﻿#ifndef _AssetFile_h
#define _AssetFile_h

#include "cstdio"

class CocoAssetFile
{
private:
    static char* filesPath;
    static char* assetPath;

protected:
    void* fd;
    char* file;
    char* data;
    bool isAsset;
    size_t length;

public:
    static void init(const char* i_filesPath, const char* i_assetPath)
    {
        filesPath = strdup(i_filesPath);
        assetPath = strdup(i_assetPath);
    }
    static void quit()
    {
        free(filesPath); filesPath = nullptr;
        free(assetPath); assetPath = nullptr;
    }
    static bool exists(const char* str, bool isAsset)
    {
        if(isAsset && assetPath && str)
        {
            std::string temps(assetPath);
            temps += str + 2;
            FILE* f = fopen(temps.c_str(), "rb");
            if(f) fclose(f);
            else return false;
        }
        else if(!isAsset && filesPath && str)
        {
            std::string temps(filesPath);
            temps += str + 2;
            FILE* f = fopen(temps.c_str(), "rb");
            if(f) fclose(f);
            else return false;
        }
        else return false;
        return true;
    }
    static CocoAssetFile* open(const char* str)
    {
        CocoAssetFile* ret = nullptr;
        if(str && strlen(str) > 2 && str[0] == '.' && str[1] == '/')
        {
            if(exists(str, false)) ret = new CocoAssetFile(str, false);
            else if(exists(str, true)) ret = new CocoAssetFile(str, true);
        }
        return ret;
    }
    static bool create(const char* str)
    {
        return createWithData(str, nullptr, 0);
    }
    static bool createWithData(const char* str, const char* data, size_t size = 0)
    {
        if(filesPath && str)
        {
            std::string temps(filesPath);
            temps += str + 2;
            FILE* f = fopen(temps.c_str(), "wb");
            if(f)
            {
                if(data)
                {
                    if(!size) size = strlen(data);
                    fwrite(data, 1, size, f);
                }
                fclose(f);
            }
            else return false;
        }
        else return false;
        return true;
    }
    CocoAssetFile(const char* str, bool i_isAsset) : fd(nullptr), file(nullptr), data(nullptr), isAsset(i_isAsset), length(0)
    {
        if(isAsset && assetPath && str)
        {
            std::string temps(assetPath);
            temps += str + 2;
            file = strdup(temps.c_str());
            fd = fopen(file, "rb");
            if(fd)
            {
                fseek((FILE*)fd, 0, SEEK_END);
                length = ftell((FILE*)fd);
                rewind((FILE*)fd);
                trace("ASSET OPEN(\"%s\")!\n", str);
            }
            else trace("ASSET ERROR OPEN: %s\n", file);
        }
        else if(!isAsset && filesPath && str)
        {
            std::string temps(filesPath);
            temps += str + 2;
            file = strdup(temps.c_str());
            fd = fopen(file, "rb+");
            if(fd)
            {
                fseek((FILE*)fd, 0, SEEK_END);
                length = ftell((FILE*)fd);
                rewind((FILE*)fd);
                trace("FILE OPEN(\"%s\")!\n", str);
            }
            else trace("FILE ERROR OPEN: %s\n", file);
        }
    }
    ~CocoAssetFile()
    {
        if(fd)
        {
            fclose((FILE*)fd);
            fd = nullptr;
        }
        delete[] file;
        delete[] data;
    }
    char* getData()
    {
        if(!fd) return nullptr;
        if(!data)
        {
            rewind((FILE*)fd);
            data = new char[length + 1];
            data[length] = 0;
            fread(data, 1, length, (FILE*)fd);
        }
        return data;
    }
    inline const size_t& getLength() const { return length; }
    inline const char* getFullPath() const { return file; }

    // standard io functions pass-through
    // they update only the file, not the data!
    inline int seek(long int offset, int origin) { return fseek((FILE*)fd, offset, origin); }
    inline long int tell() { return ftell((FILE*)fd); }
    inline size_t read(void* dest, size_t size) { return fread(dest, 1, size, (FILE*)fd); }
    inline size_t write(const void* src, size_t size) { return fwrite(src, 1, size, (FILE*)fd); }
    inline int flush() { return fflush((FILE*)fd); }
};

#endif
