## Windows GUI Graph Text Rendering

### Graphics Device Interface

##### # Concept

<u>Illustrates definition and function of GDI.</u>

**Graphics Device Interface(GDI)** is an abstraction layer between application and the physical output device, which provides a uniform interface for various output device (i.e. monitor in different resolution ratio). The dataflow can be shown as following diagram:

```mermaid
graph LR
Application --> GDI --> D[Drive Program For Device] --> Device
```

Here the `Drive Program ` is the linker between the codes that manipulates GDI, which converts the operations into the instruction of device.

Nowadays the GDI has developed into GDI+.

==TODO: What is GDI+?==



##### # Device Context

**Device Context(DC)** is a data structure that defines the graphic object and its properties.


