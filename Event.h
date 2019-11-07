//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_EVENT_H
#define ARCHIVER_EVENT_H


#include <cstdio>
#include <string>
#include <set>

struct Event {
        enum EventType {format_check_event, compress_event, decompress_event, archive_event, dearchive_event};

        struct FormatCheckEvent {
            FILE *filename;
        };

        struct CompressEvent {
            FILE *filename;
            std::string type;
        };

        struct DecompressEvent {
            FILE *filename;
            std::string type;
        };

        struct ArchiveEvent {
            std::set <FILE> files;
        };

        struct DearchiveEvent {
            FILE* filename;
        };
};


#endif //ARCHIVER_EVENT_H
