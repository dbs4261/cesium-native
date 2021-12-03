const fs = require("fs");
const path = require("path");

const getNameFromTitle = require("./getNameFromTitle");
const unindent = require("./unindent");

function generateRegisterExtensions(options) {
  const {
    readerOutputDir,
    config,
    namespace,
    readerNamespace,
    extensions,
  } = options;

  const classNames = [];
  const extensionClassNames = [];
  const registrations = [];

  for (const title in extensions) {
    const className = getNameFromTitle(config, title);
    classNames.push(className);

    const extensionsList = extensions[title];
    for (const extension of extensionsList) {
      const extensionClassName = extension.className;
      extensionClassNames.push(extensionClassName);
      registrations.push({
        className,
        extensionClassName,
      });
    }
  }

  const filename = "registerExtensions";

  const header = `
        // This file was generated by generate-classes.
        // DO NOT EDIT THIS FILE!
        #pragma once
        
        namespace CesiumJsonReader {
        class ExtensionReaderContext;
        } // namespace CesiumJsonReader
        
        namespace ${readerNamespace} {
        void registerExtensions(CesiumJsonReader::ExtensionReaderContext& context);
        };
    `;

  const implementation = `
        // This file was generated by generate-classes.
        // DO NOT EDIT THIS FILE!
        
        #include "${readerNamespace}/${filename}.h"
        
        #include <CesiumJsonReader/ExtensionReaderContext.h>

        ${classNames
          .map((className) => {
            return `#include <${namespace}/${className}.h>`;
          })
          .join("\n")}
        
        ${extensionClassNames
          .map((extensionClassName) => {
            return `#include <${readerNamespace}/${extensionClassName}JsonHandler.h>`;
          })
          .join("\n")}  

        namespace ${readerNamespace} {
        
        void registerExtensions(CesiumJsonReader::ExtensionReaderContext& context) {
          (void)context;
          ${registrations
            .map((registration) => {
              return `context.registerExtension<${namespace}::${registration.className}, ${registration.extensionClassName}JsonHandler>();`;
            })
            .join("\n")}
        }
        } // namespace ${readerNamespace}
  
  `;

  const readerHeaderOutputDir = path.join(
    readerOutputDir,
    "generated",
    "src",
    readerNamespace
  );
  fs.mkdirSync(readerHeaderOutputDir, { recursive: true });

  const headerOutputPath = path.join(readerHeaderOutputDir, `${filename}.h`);

  const implementationOutputPath = path.join(
    readerHeaderOutputDir,
    `${filename}.cpp`
  );

  fs.writeFileSync(headerOutputPath, unindent(header), "utf-8");
  fs.writeFileSync(implementationOutputPath, unindent(implementation), "utf-8");
}

module.exports = generateRegisterExtensions;
