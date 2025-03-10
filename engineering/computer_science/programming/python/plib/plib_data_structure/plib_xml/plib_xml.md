# Python Library `xml.etree.ElementTree`

We parse the XML by `ET.parse()` method from file or `ET.fromstring()` method from string.

```python
import xml.etree.ElementTree as ET
tree = ET.parse('xml.xml')
root = tree.getroot()
```

```python
root = ET.fromstring("""<langs>
	<c rank="1"></c>
	<python rank="2"></python>
	<go rank="10"></go>
</langs>""")
```

Note that the returned value of `ET.parse()` is the ElementTree object `<class 'xml.etree.ElementTree.ElementTree'>`, while `ET.fromstring()` returns the root element with type `<class 'xml.etree.ElementTree.Element'>`.

The tag label and atttibutes of XML tag can be accessed by the `tag` and `attrib` property.

`for` loop is supported to iterate the children of element:

```python
for lang in root:
    print(lang.tag, lang.attrib)
"""
c {'rank': '1'}
python {'rank': '2'}
go {'rank': '10'}
"""
```


