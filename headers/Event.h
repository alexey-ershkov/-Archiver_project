//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_EVENT_H
#define ARCHIVER_EVENT_H



#include <string>
#include <variant>


struct Event {
        enum eventType {format_check_event,
                compress_event,
                decompress_event,
                archive_event,
                dearchive_event,
                test_event};

        struct formatCheckEvent {
            FILE *filename;
        };

        struct compressEvent {
            FILE *filename;
            std::string type;
        };

        struct decompressEvent {
            FILE *filename;
            std::string type;
        };

        struct archiveEvent {
            std::set <FILE> files;
        };

        struct dearchiveEvent {
            FILE* filename;
        };

        struct testEvent {
            std::string test = "TestEvent";
        };

        eventType type;
        std::variant<formatCheckEvent, compressEvent, decompressEvent, archiveEvent, dearchiveEvent, testEvent> data;
};


#endif //ARCHIVER_EVENT_H
